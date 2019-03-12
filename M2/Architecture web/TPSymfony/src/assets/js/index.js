function on_submit(evt){
    let result = document.getElementById('pass').value === document.getElementById('pass-confirm').value;
    if(!result){
        alert('Les mots de passes ne correspondent pas');
    }
    return result;
}