<?php
    require_once 'vendor/autoload.php';
    require_once 'bootstrap.php';
    $utilisateurRepository = $entityManager->getRepository('Utilisateur');

    $LOADER = new Twig_Loader_Filesystem('src/templates/');
    $TWIG = new Twig_Environment($LOADER, array(
        'cache' => false
    ));

    function load_template($template){
        global $TWIG;
        return $TWIG->loadTemplate("$template.twig.html");
    }

    function mail_exists($user){
        global $utilisateurRepository;
        return $utilisateurRepository->findBy(['mail' => $user->getEmail()]) !== null;
    }

    function login_exists($user){
        global $utilisateurRepository;
        return $utilisateurRepository->findBy(['login' => $user->getLogin()]) !== null;
    }

    function register_user($form){
        global $entityManager;
        global $error;
        $user = new Utilisateur();
        $user->setNom($form['nom']);
        $user->setPrenom($form['prenom']);
        $user->setAdresse($form['adresse']);
        $user->setCodePostale($form['cp']);
        $user->setVille($form['ville']);
        $user->setEmail($form['email']);
        $user->setTelephone($form['telephone']);
        $user->setLogin($form['login']);
        $user->setPass(password_hash($form['pass'], PASSWORD_BCRYPT));
        $mail_exists = mail_exists($user);
        $login_exists = login_exists($user);
        if(!mail_exists && !login_exists){
            $entityManager->persist($user);
            $entityManager->flush();
        }
        return $user;
    }

    $app = new \Slim\App;
    $app->redirect('/', '/home', 301);
    $app->get('/home', function($req, $resp, $args){
        return $resp->write(load_template('home')->render([]));
    });
    $app->get('/login', function($req, $resp, $args){
        return $resp->write(load_template('login')->render([]));
    });
    $app->get('/signup', function($req, $resp, $args){
        return $resp->write(load_template('signup')->render([]));
    });
    $app->post('/signup-validate', function($req, $resp, $args){
        $user = $req->getParsedBody();
        $user = register_user($user);
        return $resp->write(load_template('signup-validate')->render([
            'user' => $user
        ]));
    });
    $app->run();
?>