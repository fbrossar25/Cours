<?php
	ob_start();
	require('bibli_cuiteur.php');
	$BD =  fb_bd_connection();
	if(mysqli_connect_errno())
	{
		echo "Failed to connect to the DataBase : ".mysqli_connect_error();
	}
	$nom = "Chuck Norris";
	$Req = 'SELECT usPseudo FROM users WHERE usNom = "'.$nom.'"';
	$R = mysqli_query($BD,$Req) OR fd_bd_erreur($BD, $Req);
	$S = mysqli_fetch_assoc($R);
	$pseudo = htmlentities($S['usPseudo'],ENT_QUOTES,'ISO-8859-1');
	fb_html_debut('Liste de blablas');
	echo'<body>',
		'<h1>Liste des blablas de '.$nom.'</h1>';
	//Req
	$Req = 'SELECT *
			FROM blablas 
			WHERE blIDAuteur = 
				(SELECT usID 
				FROM users 
				WHERE usPseudo = "nono")
			ORDER BY blDate DESC';
	//executer
	$R = mysqli_query($BD,$Req) OR fd_bd_erreur($BD, $Req);
	echo '<h2>Blablas &eacute;crit par '.$nom.'</h2>';
	//Affichage des blablas
	echo '<ul>';
	while($S = mysqli_fetch_assoc($R)){//blablas chuck
		echo 	'<li>',$pseudo,' - ',$nom,'<br>',
				htmlentities($S['blTexte'],ENT_QUOTES,'ISO-8859-1'),'<br>',
				fb_amj_clair(htmlentities($S['blDate'],ENT_QUOTES,'ISO-8859-1')),' - ',htmlentities($S['blHeure'],ENT_QUOTES,'ISO-8859-1'),
				'</li>';
	}
	echo '</ul>';
	///////////////////////////////////////blablas abonnements de chuck
	$Req = 'SELECT blDate, blHeure, usNom, usPseudo, blTexte
			FROM blablas,users,estabonne
			WHERE eaIDUser = 23
			AND usID = blIDAuteur
			AND eaIDAbonne = blIDAuteur
			AND usID = eaIDAbonne
			AND blAvecCible = 0
			ORDER BY blDate DESC';
	//executer
	$R = mysqli_query($BD,$Req) OR fd_bd_erreur($BD, $Req);
	//Affichage des blablas
	echo'<h2>Blablas des abonnements de '.$nom.'</h2>',
		'<ul>';
	while($S = mysqli_fetch_assoc($R)){//blablas chuck
		echo 	'<li>',$S['usPseudo'],' - ',$S['usNom'],'<br>',
				htmlentities($S['blTexte'],ENT_QUOTES,'ISO-8859-1'),'<br>',
				fb_amj_clair(htmlentities($S['blDate'],ENT_QUOTES,'ISO-8859-1')),' - ',htmlentities($S['blHeure'],ENT_QUOTES,'ISO-8859-1'),
				'</li>';
	}
	echo '</ul>';
	///////////////////////////////////////
	echo '<a href="../index.php" title="Index">Retourner &agrave; l\'index</a>',
		 '</body>',
		 '</html>';
	mysqli_free_result($R);
	mysqli_close($BD);
	ob_end_flush();
?>
