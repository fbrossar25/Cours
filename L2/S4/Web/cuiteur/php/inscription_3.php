<?php
	ob_start();
	require('bibli_cuiteur.php');
	echo'<!DOCTYPE html>',
		'<html>',
			'<head>',
				'<title>Cuiteur Inscription</title>',
				'<meta charset="iso-8859-1">',
			'</head>',
			'<body>',
				'<h1>Réception du formulaire<br>Inscription utilisateur</h1>';
				
				//Traitements des erreurs
				$erreurs = array();
				if($_POST['txtPseudo'] == '' || strlen($_POST['txtPseudo']) < 4 || strlen($_POST['txtPseudo']) > 30){
					$erreurs[] = 'Le pseudo doit avoir de 4 à 30 caractères';
				}
				else if(pseudoAlreadyExist($_POST['txtPseudo'])){
					$erreurs[] = 'Le pseudo doit être changé';
				}
				if($_POST['txtPass'] == ''){
					$erreurs[] = ' Le mot de passe est obligatoire';
				}
				if($_POST['txtVerif'] != $_POST['txtPass']){
					$erreurs[] = 'Le mot de passe est différent dans les 2 zones';
				}
				if($_POST['txtNom'] == ''){
					$erreurs[] = ' Le nom est obligatoire';
				}
				if($_POST['txtMail'] == '' || strpos($_POST['txtMail'],'@') == False || strpos($_POST['txtMail'],'.') == False){
					$erreurs[] = ' L\'adresse mail est obligatoire / L\'adresse mail n\'est pas valide';
				}
				if(!checkDate($_POST['selNais_m'],$_POST['selNais_j'],$_POST['selNais_a'])){
					$erreurs[] = 'La date de naissance n\'est pas valide';
				}
				//affichages des erreurs
				if(count($erreurs) == 0){
					echo '<p>Aucune erreur détectée.</p>';
				}
				else{
					echo'<p><strong>Les erreurs suivantes ont été détectées : </strong></p>',
						'<p>';
					foreach($erreurs as $value){
						echo $value,'<br>';
					}
					echo '</p>';
				}
		echo	'<p>',
					'<a href="../index.php" title="Index">Retourner à l\'index</a><br>',
					'<a href="../html/inscription_2.html" title="Formulaire">Retourner au formulaire d\'inscription</a>',
				'</p>',
			'</body>',
		'</html>';
	ob_end_flush();
?>