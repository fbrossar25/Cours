erreurs = [];

function ajouterErreurs(erreur){
    if(!erreurs.includes(erreur)){
        erreurs.push(erreur);
    }
}

function supprimerErreurs(erreur){
    for(let i = erreurs.length-1; i >= 0; i--){
        if(erreurs[i] === erreur){
            erreurs.splice(i,1);
        }
    }
}

function valeurFormulaire(champ){
    //Comment vérifier que ça viens bien du formulaire ??
    return document.getElementById(champ).value;
}

function validerMotDePasse(){
    let CORRESPONDANCE = 'Les mots de passes ne correspondent pas';
    let TAILLE = 'Le mot de passe doit contenir au moins 6 caractères';

    if(valeurFormulaire('pass') !== valeurFormulaire('pass-confirm')){
        ajouterErreurs(CORRESPONDANCE);
    }else{
        supprimerErreurs(CORRESPONDANCE);
    }

    if(valeurFormulaire('pass').length < 6){
        ajouterErreurs(TAILLE);
    }else{
        supprimerErreurs(TAILLE);
    }
}

function validerTelephone(){
    let reg = /^\d+$/;
    let MESSAGE = "Le numéro de téléphone n'est pas valide"
    if(!reg.test(valeurFormulaire('telephone'))){
        ajouterErreurs(MESSAGE);
    }else{
        supprimerErreurs(MESSAGE);
    }
}

function afficherErreurs(){
    let divErreurs = document.getElementById('erreurs');
    if(erreurs.length === 0){
        divErreurs.classList.add('hidden');
        document.getElementById('liste-erreurs').innerHTML = '';
        return;
    }
    divErreurs.classList.remove('hidden');
    let listeErreurs = document.getElementById('liste-erreurs');
    let htmlErreurs = '';
    erreurs.forEach(erreur => htmlErreurs += '<li>' + erreur + '</li>')
    listeErreurs.innerHTML = htmlErreurs;
}

function validerChampsNonVide(){
    let CHAMPS = ['nom', 'prenom', 'adresse', 'code-postale', 'ville', 'email', 'login', 'telephone'];
    CHAMPS.forEach((champ) => {
        let MESSAGE = 'Le champ ' + champ + ' ne dois pas être vide';
        if(valeurFormulaire(champ).length === 0){
            ajouterErreurs(MESSAGE);
        }else{
            supprimerErreurs(MESSAGE);
        }
    });
}

function validerFormulaire(evt){
    evt.preventDefault();
    let erreurs = [];
    validerChampsNonVide();
    validerMotDePasse();
    validerTelephone();
    afficherErreurs(erreurs);
}

document.getElementById('pass').addEventListener('keyup', (evt) => {
    validerMotDePasse();
    afficherErreurs();
});
document.getElementById('pass-confirm').addEventListener('keyup', (evt) => {
    validerMotDePasse();
    afficherErreurs();
});

// document.getElementById("btn-valider").addEventListener('click', (evt) => {
//     validerFormulaire();
// });