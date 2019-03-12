<?php
    require 'vendor/autoload.php';

    $LOADER = new Twig_Loader_Filesystem('src/templates/');
    $TWIG = new Twig_Environment($LOADER, array(
        'cache' => false
    ));

    function load_template($template){
        global $TWIG;
        return $TWIG->loadTemplate("$template.twig.html");
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
        $user['pass'] = password_hash($user['pass'], PASSWORD_BCRYPT);
        return $resp->write(load_template('signup-validate')->render([
            'user' => $user
        ]));
    });
    $app->run();
?>