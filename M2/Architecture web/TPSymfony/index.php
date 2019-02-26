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
        return $resp->write(load_template('home')->render(array()));
    });
    $app->get('/login', function($req, $resp, $args){
        return $resp->write(load_template('login')->render(array()));
    });
    $app->get('/signup', function($req, $resp, $args){
        return $resp->write(load_template('signup')->render(array()));
    });
    $app->post('/signup', function($req, $resp, $args){
        return "Inscription pas encore implémentée";
    });
    $app->run();
?>