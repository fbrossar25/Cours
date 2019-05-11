<?php
	//___________________________________________________________________
	/**
	* Fonction calculant les différents erreurs pouvant survenirs et retournant un tableau avec ces erreurs (ou tableau vide si aucune erreurs)
	* @param	array	$data		les données saisie par l'utilisateur dans le formulaire
	* @return	array	$erreurs	les éventuelles erreurs, vide si aucune erreurs
	*/
	function fbl_new_user($data){
		//on vérifie en premier systématiquement si $data est vide pour éviter des erreurs
		$errors = array();
		if($data == NULL || strlen($data['txtPseudo']) < 4 || strlen($data['txtPseudo']) > 30){
			$errors[] = 'Le pseudo doit avoir de 4 à 30 caractères';
		}
		else if(pseudoAlreadyExist($data['txtPseudo'])){
			$errors[] = 'Le pseudo doit être changé';
		}
		if($data == NULL || $data['txtPass'] == ''){
			$errors[] = 'Le mot de passe est obligatoire';
		}
		if($data == NULL || $data['txtVerif'] != $data['txtPass']){
			$errors[] = 'Le mot de passe est différent dans les 2 zones';
		}
		if($data == NULL || $data['txtNom'] == ''){
			$errors[] = 'Le nom est obligatoire';
		}
		if($data == NULL || $data['txtMail'] == ''){
			$errors[] = 'L\'adresse mail est obligatoire';
		}
		else if(strpbrk($data['txtMail'],'@.') == FALSE){
			$errors[] = 'L\'adresse mail n\'est pas valide';
		}
		if($data == NULL || !checkDate($data['selNais_m'],$data['selNais_j'],$data['selNais_a'])){
			$errors[] = 'La date de naissance n\'est pas valide';
		}
		if(count($errors) == 0){//redirection vers la liste des utilisateurs
			registerNewUser($data);
			header ('location: liste_users_3.php');
			exit();
		}
		return $errors;
	}

	require('bibli_cuiteur.php');
	$erreurs = array();
	if($_POST != NULL){//Phase de soumission
		$erreurs = fbl_new_user($_POST);
	}
	fb_html_debut("Cuiteur Inscription");
	echo'<body>';
		if(count($erreurs) != 0){//Erreur de saisie ==> affichage des erreurs
			echo'<p><strong>Les erreurs suivantes ont été détectées : </strong></p>',
					'<p>';
					foreach($erreurs as $value){
						echo $value,'<br>';
					}
				echo'</p>';
		}
		//Affichage formulaire
		if($_POST == NULL){//valeurs par défaut
			$pseudo = "";
			$pass = "";
			$passVerif = "";
			$nom = "";
			$mail = "";
		}
		else{//valeur données précédement
			$pseudo = $_POST['txtPseudo'];
			$pass = $_POST['txtPass'];
			$passVerif = $_POST['txtVerif'];
			$nom = $_POST['txtNom'];
			$mail = $_POST['txtMail'];
		}
		echo'<table border="1" cellpadding="4" cellspacing="0">',
				'<form method=POST action="inscription.php">',
					'<tr>',
						'<td>Choisir un pseudo</td>',
						'<td>',
							'<input type="text" name="txtPseudo" size="20" value="'.$pseudo.'">',
						'</td>',
					'</tr>',
					'<tr>',
						'<td>Choisir un mot de passe</td>',
						'<td>',
							'<input type="password" name="txtPass" size="20" value="'.$pass.'">',
						'</td>',
					'</tr>',
					'<tr>',
						'<td>Répéter le mot de passe</td>',
						'<td>',
							'<input type="password" name="txtVerif" size="20" value="'.$passVerif.'">',
						'</td>',
					'</tr>',
					'<tr>',
						'<td>Indiquer votre nom</td>',
						'<td>',
							'<input type="text" name="txtNom" size="40" value="'.$nom.'">',
						'</td>',
					'</tr>',
					'<tr>',
						'<td>Donner votre adresse mail</td>',
						'<td>',
							'<input type="text" name="txtMail" size="40" value="'.$mail.'">',
						'</td>',
					'</tr>',
					'<tr>',
						'<td>Votre date de naissance</td>',
						'<td>',
							'<select name="selNais_j">',
								'<option value=1>1</option>',
								'<option value=2>2</option>',
							'</select>',
							'<select name="selNais_m">',
								'<option value=1>Janvier</option>',
								'<option value=2>Février</option>',
							'</select>',
							'<select name="selNais_a">',
								'<option value=2010>2010</option>',
								'<option value=2011>2011</option>',
							'</select>',
						'</td>',
					'</tr>',
					'<tr>',
						'<td></td>',
						'<td>',
							'<input type="submit" value="Je m\'inscris !" name="btnValider">',
						'</td>',
					'</tr>',
				'</form>',
			'</table>',
			'<a href="../index.php" title="Index">Retourner à l\'index</a>';
	echo'</body>';
	ob_start();
	ob_end_flush();
?>