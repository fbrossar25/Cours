function on_submit(evt){
    let result = document.getElementById('pass').value === document.getElementById('confirm').value;
    if(!result){
        alert('Les mots de passes ne correspondent pas');
    }
    return result;
}