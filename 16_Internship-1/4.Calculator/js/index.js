class Calculator{
    constructor(datapreviousOperand,dataCurrentOperand){
        this.datapreviousOperand=datapreviousOperand;
        this.dataCurrentOperand=dataCurrentOperand;
        this.clear();
    }

    clear(){
        this.currentOperand='';
        this.previousOperand='';
        this.operation=undefined;
    }

    appendNumber(number){

        if(number==='.' && this.currentOperand.includes('.')) {return}
        this.currentOperand=this.currentOperand.toString()+ number;
    }


    chooseOperation(operation){

        if(this.currentOperand===''){return }

        if(this.previousOperand!==''){
            this.calculate();
        }
        this.operation=operation;
        this.previousOperand=this.currentOperand;
        this.currentOperand='';
    }
    
    updateDisplay(){
        this.dataCurrentOperand.innerText=this.currentOperand;
        
        if(this.operation!==undefined){
        this.datapreviousOperand.innerText=`${this.previousOperand} ${this.operation}`;
    }

    else {
        this.datapreviousOperand.innerText='';
    }
    }

    calculate(){

        let answer;
        const previous=parseFloat(this.previousOperand);
        const current=parseFloat(this.currentOperand);

        if(isNaN(previous) || isNaN(current)){return}

        switch(this.operation){
            case '+':
                answer=previous+current;
                break;
            case '-':

                answer=previous-current;
                break;
            case '*':
                answer=current*previous;
                break;
            case '÷':
                answer=current/previous;
                break;


        }

        this.currentOperand=answer;
        this.previousOperand='';
        this.operation=undefined;

    }


    delete(){
        this.currentOperand=this.currentOperand.toString().slice(0,-1);
    }
}

const numberButtons=document.querySelectorAll('[dataNumber]');
const operationButtons=document.querySelectorAll('[dataOperation]');
const equalButton=document.querySelector('[dataEquals]');
const dataDelete=document.querySelector('[dataDelete]');
const dataAllClear=document.querySelector('[dataAllClear]');
const datapreviousOperand=document.querySelector('[dataPreviousOperand]');
const dataCurrentOperand=document.querySelector('[dataCurrentOperand]');


const obj=new Calculator(datapreviousOperand,dataCurrentOperand);

numberButtons.forEach(button =>{
    button.addEventListener('click',()=>{
        obj.appendNumber(button.innerText);
        obj.updateDisplay();
    })
})


operationButtons.forEach(button =>{
    button.addEventListener('click',()=>{
        obj.chooseOperation(button.innerText);
        obj.updateDisplay();
    })
})

equalButton.addEventListener('click',button =>{
    obj.calculate();
    obj.updateDisplay();
})

dataAllClear.addEventListener('click',button =>{
    obj.clear();
    obj.updateDisplay();
})

dataDelete.addEventListener('click',button =>{
    obj.delete();
    obj.updateDisplay();
})