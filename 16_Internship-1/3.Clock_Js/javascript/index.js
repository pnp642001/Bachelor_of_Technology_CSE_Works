let temp;
let time;
let date;

setInterval(() => {
    
    temp = new Date();

     date=temp.toLocaleDateString();
     time=temp.getHours()+" : "+temp.getMinutes()+" : "+temp.getSeconds();

    document.getElementById("time").innerHTML=time;
    document.getElementById("date").innerHTML=date;

}, 1000);