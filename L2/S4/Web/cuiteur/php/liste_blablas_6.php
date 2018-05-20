<?php
	ob_start();
	require('bibli_cuiteur.php');
	$BD = fb_bd_connection();
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
	fb_html_debut('Liste de blablas','tp3');
	echo'<body id="bcPage">',
		'<h1>Liste des blablas de '.$nom.'</h1>';
	////////////////////////////////////////
	//Req
		$Req = 'SELECT blDate, blHeure, usNom, usPseudo, blTexte, blIDAuteur
				FROM blablas,users 
				WHERE blIDAuteur = usID
				AND usID = '.$userID.'
				UNION
				SELECT blDate, blHeure, usNom, usPseudo, blTexte, blIDAuteur
				FROM blablas,users,estabonne
				WHERE eaIDUser = 23
				AND usID = blIDAuteur
				AND eaIDAbonne = blIDAuteur
				AND usID = eaIDAbonne
				AND blAvecCible = 0
				UNION
				SELECT blDate, blHeure, usNom, usPseudo, blTexte, blIDAuteur
				FROM blablas,users,mentions
				WHERE meIDUser = 23
				AND meIDBlabla = blID
				AND blIDAuteur = usID
				ORDER BY blDate,blHeure DESC';
	//executer
	$R = mysqli_query($BD,$Req) OR fd_bd_erreur($BD, $Req);
	fb_aff_blablas($R);
	///////////////////////////////////////
	echo '<a href="../index.php" title="Index">Retourner &agrave; l\'index</a>',
		 '</body>',
	'</html>';
	mysqli_free_result($R);
	mysqli_close($BD);
	ob_end_flush();
?>