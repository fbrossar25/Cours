<?php
    require 'vendor/autoload.php';

    $loader = new Twig_Loader_Filesystem('vendor/src/templates/');
    $twig = new Twig_Environment($loader, array(
        'cache' => false
    ));
    $template = $twig->loadTemplate('form.twig.html');
    echo $template->render(array('title' => "Formulaire d'inscription"))
?>