<?php
	ob_start();
	require('bibli_cuiteur.php');
	$BD =  fb_bd_connection();
	if(mysqli_connect_errno())
	{
		echo "Failed to connect to the DataBase : ".mysqli_connect_error();
	}
	$userID=23;
	$Req = 'SELECT usPseudo,usNom FROM users WHERE usID = "'.$userID.'"';
	$R = mysqli_query($BD,$Req) OR fd_bd_erreur($BD, $Req);
	$S = mysqli_fetch_assoc($R);
	$pseudo = htmlentities($S['usPseudo'],ENT_QUOTES,'ISO-8859-1');
	$nom = htmlentities($S['usNom'],ENT_QUOTES,'ISO-8859-1');
	fb_html_debut('Liste de blablas');
	echo'<body>',
		'<h1>Liste des blablas de '.$nom.'</h1>';
	////////////////////////////////////////
	//Req
		$Req = 'SELECT blDate, blHeure, usNom, usPseudo, blTexte, blIDAuteur
				FROM blablas, users 
				WHERE blIDAuteur = usID
				AND blIDAuteur = 
					(SELECT usID 
					FROM users 
					WHERE usPseudo = "nono")
				ORDER BY blDate DESC';
	//executer
	$R = mysqli_query($BD,$Req) OR fd_bd_erreur($BD, $Req);
	echo '<h2>Blablas &eacute;crit par '.$nom.'</h2>';
	fb_aff_blablas($R);
	///////////////////////////////////////blablas abonnements de chuck
	$Req = 'SELECT blDate, blHeure, usNom, usPseudo, blTexte, blIDAuteur
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
	echo'<h2>Blablas des abonnements de '.$nom.'</h2>';
	fb_aff_blablas($R);
	///////////////////////////////////////blablas mentionnant chuck
	$Req = 'SELECT blDate, blHeure, usNom, usPseudo, blTexte, blIDAuteur
			FROM blablas,users,mentions
			WHERE meIDUser = 23
			AND meIDBlabla = blID
			AND blIDAuteur = usID
			ORDER BY blDate,blHeure DESC';
	//executer
	$R = mysqli_query($BD,$Req) OR fd_bd_erreur($BD, $Req);
	//Affichage des blablas
	echo'<h2>Blablas mentionnant '.$nom.'</h2>';
	fb_aff_blablas($R);
	///////////////////////////////////////
	echo '<a href="../index.php" title="Index">Retourner &agrave; l\'index</a>',
		 '</body>',
	'</html>';
	mysqli_free_result($R);
	mysqli_close($BD);
	ob_end_flush();
?>