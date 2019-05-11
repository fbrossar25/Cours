<?php
	ob_start();
	echo'<!DOCTYPE html>',
		'<html>',
			'<head>',
				'<title>Cuiteur Inscription</title>',
				'<meta charset="iso-8859-1">',
			'</head>',
			'<body>',
				'<h1>Réception du formulaire<br>Inscription utilisateur</h1>',
				'<a href="../index.php" title="Index">Retourner à l\'index</a>',
				'<p>';
				foreach($_POST as $cle => $valeur){
					echo'Zone ',$cle,' = ',$valeur,'<br>';
				}
			echo'</p>',
			'</body>',
		'</html>';
	ob_end_flush();
?>