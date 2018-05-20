<?php
	ob_start();
	//___________________________________________________________________
	/**
	 * Gestion d'une erreur de requête base de données.
	 *
	 * @param resource	$bd		Connecteur sur la bd ouverte
	 * @param string	$sql	requête SQL provoquant l'erreur
	 */
	function fd_bd_erreur($bd, $sql) {
		$errNum = mysqli_errno($bd);
		$errTxt = mysqli_error($bd);

		// Collecte des informations facilitant le debugage
		$msg = '<h4>Erreur de requête</h4>'
				."<pre><b>Erreur mysql :</b> $errNum"
				."<br> $errTxt"
				."<br><br><b>Requête :</b><br> $sql"
				.'<br><br><b>Pile des appels de fonction</b>';

		// Récupération de la pile des appels de fonction
		$msg .= '<table border="1" cellspacing="0" cellpadding="2">'
				.'<tr><td>Fonction</td><td>Appelée ligne</td>'
				.'<td>Fichier</td></tr>';

		$appels = debug_backtrace();
		for ($i = 0, $iMax = count($appels); $i < $iMax; $i++) {
			$msg .= '<tr align="center"><td>'
					.$appels[$i]['function'].'</td><td>'
					.$appels[$i]['line'].'</td><td>'
					.$appels[$i]['file'].'</td></tr>';
		}

		$msg .= '</table></pre>';

		fd_bd_erreurExit($msg);
	}			
	//___________________________________________________________________
	/**
	 * Arrêt du script si erreur base de données.
	 * Affichage d'un message d'erreur si on est en phase de
	 * développement, sinon stockage dans un fichier log.
	 *
	 * @param string	$msg	Message affiché ou stocké.
	 */
	function fd_bd_erreurExit($msg) {
		ob_end_clean();		// Supression de tout ce qui
						// a pu être déja généré

		echo '<!DOCTYPE html><html><head><meta charset="ISO-8859-1"><title>',
				'Erreur base de données</title></head><body>',
				$msg,
				'</body></html>';
		exit();
	}
	echo 	'<!DOCTYPE HTML>',
			'<html>',
			'<head>',
				'<title>Liste des utilisateurs</title>',
			'</head>',
			'<body>',
			'<h1>Liste des utilisateurs de Cuiteur</h1>';
	//connexion à BD
	$BD = mysqli_connect('localhost','brossard_u','brossard_p','brossard_cuiteur');
	if(mysqli_connect_errno())
	{
		echo "Failed to connect to the DataBase : ".mysqli_connect_error();
	}
	//Req
	$Req = 'SELECT * FROM users ORDER BY usID';
	//executer
	$R = mysqli_query($BD,$Req) OR fd_bd_erreur($bd, $sql);
	
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
							'<li>Naissance : ',htmlentities($S['usDateNaissance'],ENT_QUOTES,'ISO-8859-1'),'</li>',
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
