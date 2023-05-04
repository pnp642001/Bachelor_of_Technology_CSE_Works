let addNote = document.getElementById("button-1");

displayNotes();
addNote.addEventListener("click", function (obj) {
  let textNote = document.getElementById("textArea-1");

  let textTitle=document.getElementById("title");

  let notes = localStorage.getItem("notes");

  if (notes == null) {
    noteObject = [];
  } else {
    noteObject = JSON.parse(notes);
  }

  let finalObject={
    title:textTitle.value,
    text:textNote.value
  }
  noteObject.push(finalObject);
  localStorage.setItem("notes", JSON.stringify(noteObject));

  textNote.value = "";
  textTitle.value="";

  displayNotes();
});

function displayNotes() {
  let notes = localStorage.getItem("notes");

  if (notes == null) {
    noteObject = [];
  } else {
    noteObject = JSON.parse(notes);
  }

  let str = "";

  noteObject.forEach(function (element, index) {
    str += ` 
        <div class="userEnteredNotes card my-2 mx-2" style="width: 18rem">

            <div class="card-body">
            <h4>
             ${element.title}
             </h4>
                <p class="card-text">

                ${element.text}
                </p>

                <button class="btn btn-outline-danger btn-warning" id="${index}" onclick="deleteNotes(this.id)">

                    Delete
                </button>
            </div>
        </div>
    </div>`;
  });

  let element = document.getElementById("notes");

  if(noteObject.length!=0){
    element.innerHTML = str;
  }

  else
  {
      element.innerHTML=`<h3>No Notes Added!!!</h3>`;
  }

}



function deleteNotes(index)
{
    let notes = localStorage.getItem("notes");

    if (notes == null) {
      noteObject = [];
    } else {
      noteObject = JSON.parse(notes);
    }
    
    noteObject.splice(index,1);
    localStorage.setItem("notes",JSON.stringify(noteObject));
    displayNotes();
}
