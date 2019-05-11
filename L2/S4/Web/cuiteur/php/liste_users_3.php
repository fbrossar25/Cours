<?php
	ob_start();
	require('bibli_cuiteur.php');
	fb_html_debut('Liste des utilisateurs');
	echo'<body>',
		'<h1>Liste des utilisateurs de Cuiteur</h1>';
	$BD =  fb_bd_connection();
	if(mysqli_connect_errno())
	{
		echo "Failed to connect to the DataBase : ".mysqli_connect_error();
	}
	//Req
	$Req = 'SELECT * FROM users ORDER BY usID';
	//executer
	$R = mysqli_query($BD,$Req) OR fd_bd_erreur($BD, $Req);
	
			//Affichage
			while($S = mysqli_fetch_assoc($R)){
				echo	'<h2>Utilisateur ',htmlentities($S['usID'],ENT_QUOTES,'ISO-8859-1'),'</h2>',
						'<ul>',
							'<li>Pseudo : ',htmlentities($S['usPseudo'],ENT_QUOTES,'ISO-8859-1'),'</li>',
							'<li>Nom : ',htmlentities($S['usNom'],ENT_QUOTES,'ISO-8859-1'),'</li>',
							'<li>Iscription : ',htmlentities($S['usDateInscription'],ENT_QUOTES,'ISO-8859-1'),'</li>',
							'<li>Ville : ',htmlentities($S['usVille'],ENT_QUOTES,'ISO-8859-1'),'</li>',
							'<li>Web : ',htmlentities($S['usWeb'],ENT_QUOTES,'ISO-8859-1'),'</li>',
							'<li>Mail : ',htmlentities($S['usMail'],ENT_QUOTES,'ISO-8859-1'),'</li>',
							'<li>Naissance : ',fb_amj_clair(htmlentities($S['usDateNaissance'],ENT_QUOTES,'ISO-8859-1')),'</li>',
							'<li>Bio : ',htmlentities($S['usBio'],ENT_QUOTES,'ISO-8859-1'),'</li>',
						'</ul>';
			}
	echo	'<li><a href="../index.php" title="Index">Retourner &agrave; l\'index</a></li>',
			'</body>',
			'</html>';
	mysqli_free_result($R);
	mysqli_close($BD);
	ob_end_flush();
?>
