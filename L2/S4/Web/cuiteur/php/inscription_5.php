<?php
	/**
	* Fonction calculant les différents erreurs pouvant survenirs et retournant un tableau avec ces erreurs (ou tableau vide si aucune erreurs)
	* @param	array	$data		les données saisie par l'utilisateur dans le formulaire
	* @return	array	$erreurs	les éventuelles erreurs, vide si aucune erreurs
	*/
	function fbl_new_user($data){
		//on vérifie en premier systématiquement si $data est vide pour éviter des erreurs
		$erreurs = array();
		if($data == NULL || strlen($data['txtPseudo']) < 4 || strlen($data['txtPseudo']) > 30){
			$erreurs[] = 'Le pseudo doit avoir de 4 à 30 caractères';
		}
		else if(pseudoAlreadyExist($data['txtPseudo'])){
			$erreurs[] = 'Le pseudo doit être changé';
		}
		if($data == NULL || $data['txtPass'] == ''){
			$erreurs[] = 'Le mot de passe est obligatoire';
		}
		if($data == NULL || $data['txtVerif'] != $data['txtPass']){
			$erreurs[] = 'Le mot de passe est différent dans les 2 zones';
		}
		if($data == NULL || $data['txtNom'] == ''){
			$erreurs[] = 'Le nom est obligatoire';
		}
		if($data == NULL || $data['txtMail'] == ''){
			$erreurs[] = 'L\'adresse mail est obligatoire';
		}
		else if(strpbrk($data['txtMail'],'@.') == FALSE){
			$erreurs[] = 'L\'adresse mail n\'est pas valide';
		}
		if($data == NULL || !checkDate($data['selNais_m'],$data['selNais_j'],$data['selNais_a'])){
			$erreurs[] = 'La date de naissance n\'est pas valide';
		}
		if(count($erreurs) == 0){
			global $ID;
			$ID = registerNewUser($data);
		}
		return $erreurs;
	}
	
	ob_start();
	require('bibli_cuiteur.php');
	fb_html_debut("Cuiteur Inscription");
		echo'<body>',
				'<h1>Réception du formulaire<br>Inscription utilisateur</h1>';
				//Traitements et affichage des erreurs
				$erreurs = fbl_new_user($_POST);
				if(count($erreurs) == 0){//count($erreurs) == 0  ==> $_POST est valide et utilisable
				echo'<p>
						Le nouvel utilisateur à bien été enregistré<br>
						Il a le numéro '.$ID,
					'</p>';
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