'use strict'

const buttons = document.querySelectorAll(".drum");


const audio = [
    new Audio('./sounds/tom-1.mp3'),
    new Audio('./sounds/tom-2.mp3'),
    new Audio('./sounds/tom-3.mp3'),
    new Audio('./sounds/tom-4.mp3'),
    new Audio('./sounds/crash.mp3'),
    new Audio('./sounds/snare.mp3'),
    new Audio('./sounds/kick-bass.mp3'),
];


for (let i = 0; i < buttons.length; i++) {

    buttons[i].addEventListener("click", function () {
        audio[i].play();
        addButtonAnimation(this.innerHTML);
    });
    
}

document.addEventListener("keydown", event => {


    switch (event.keyCode) {
        case 87:
            addButtonAnimation(event.key);
            audio[0].play();
            break;
        case 65:
            addButtonAnimation(event.key);
            audio[1].play();
            addButtonAnimation(event.key);
            break;
        case 83:
            addButtonAnimation(event.key);
            audio[2].play();
            break;
        case 68:
            addButtonAnimation(event.key);
            audio[3].play();
            break;
        case 74:
            addButtonAnimation(event.key);
            audio[4].play();
            break;
        case 75:
            addButtonAnimation(event.key);
            audio[5].play();
            break;
        case 76:
            addButtonAnimation(event.key);
            audio[6].play();
            break;
        default:
            break;

    }
});
/* 

function makeSound(key) {
    switch(key) {

        case "w":
            audio[0].play();
            break;
        case "a":
            audio[1].play();
            break;
        case "s":
            audio[2].play();
            break;
        case "d":
            audio[3].play();
            break;
        case "j":
            audio[4].play();
            break;
        case "k":
            audio[5].play();
            break;
        case "l":
            audio[6].play();
            break;
        default:
            break;

    }
}
 */


function addButtonAnimation(currentKey) {
    const currActiveButton = document.querySelector("." + currentKey);
    currActiveButton.classList.add("pressed");
    setTimeout(() => {
        currActiveButton.classList.remove("pressed");
    }, 100);
}