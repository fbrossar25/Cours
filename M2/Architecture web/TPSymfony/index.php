<?php
    require 'vendor/autoload.php';
    require 'src/model/User.php';

    $LOADER = new Twig_Loader_Filesystem('src/templates/');
    $TWIG = new Twig_Environment($LOADER, array(
        'cache' => false
    ));

    function load_template($template){
        global $TWIG;
        return $TWIG->loadTemplate("$template.twig.html");
    }

    function form_to_user($form){
        error_log(implode(array_keys($form)));
        $user = new User();
        $user->name = $form['nom'];
        $user->lastName = $form['prenom'];
        $user->street = $form['adresse'];
        $user->postalCode = $form['code-postale'];
        $user->city = $form['ville'];
        $user->phone = $form['telephone'];
        $user->mail = $form['email'];
        $user->login = $form['login'];
        $user->pass = password_hash($form['pass'], PASSWORD_BCRYPT);
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
        $user = form_to_user($req->getQueryParams());
        return $resp->write(load_template('signup-validate')->render([
            'user' => $user
        ]));
    });
    $app->run();
?>