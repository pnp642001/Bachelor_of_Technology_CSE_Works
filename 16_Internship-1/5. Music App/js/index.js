window.addEventListener('load',() =>{

    const sound=document.querySelectorAll('[music]');
    const section=document.querySelectorAll('[section]');
    const animation=document.querySelector('.AnimationPane');

    const ballColors=[
        "#5E8B7E",
        "#0A81AB",
        "#3C415C",
        "#810000",
        "#5B5B5B",
        "#2C061F",

    ];



    section.forEach((music,index) => {
        music.addEventListener('click', ()=>{
            sound[index].currentTime=0;
            sound[index].play();

            createCircle(index);
        });

    });

    const createCircle=(index)=>{
        const circle=document.createElement("div");
        animation.appendChild(circle);

        circle.style.backgroundColor=ballColors[index];

        circle.style.animation="jump 2s ease";

        circle.addEventListener('animationend',function (){
            animation.removeChild(this);
        })
    }
});

