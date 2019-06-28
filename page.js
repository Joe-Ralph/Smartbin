
const dbRefObj = firebase.database().ref().child('alpha');

dbRefObj.on('value',snap =>{
  document.getElementById('bu').textContent=snap.val().Buzzer;
  document.getElementById('co').textContent=snap.val().CO;
  document.getElementById('fi').textContent=snap.val().Fire;
  document.getElementById('le').textContent=snap.val().Level;
  document.getElementById('la').textContent=snap.val().lat;
  document.getElementById('lo').textContent=snap.val().lon;
});