console.log("load TODOS js");

let felem = document.getElementById("formElem");
felem.onsubmit = async (e) => {
	e.preventDefault();
	let res = await fetch('/todos/post', {
	  method: 'POST'
	});
	console.log(await res.text());
};