let canvas;
let bfs;
let dfs;
let ddfs;
let wOff = 128;
let hOff = 72;
let wMin = 256;
let hMin = 144;
let wSize;
let hSize;
let inputFile;
let csv;
let size;
let speed;
let moving = -1;
let nodes = [];
let dfsOrder = [];
let bfsOrder = [];
let paintOrder = [];
let dit=0;
let bit=0;
let timer;
let date;
let bfsColors = [];
let showAll;

function setup() {

	canvas = createCanvas(windowWidth - wOff, windowHeight - hOff);
	size = createSlider(3, 100, 25);
	speed = createSlider(1, 30, 20);
	bfs = createButton('BFS');
	dfs = createButton('DFS');
	ddfs = createButton('DDFS');
	showAll = createCheckbox('Show all vertices', true);
	canvas.position((windowWidth - width) / 2,(windowHeight - height) / 2);
	bfs.position(64, 36);
	dfs.position(104, 36);
	ddfs.position(144, 36);
	showAll.position(204, 36);
	showAll.elt.style.color = "white";
	bfs.mouseClicked(callBfs);
	dfs.mouseClicked(callDfs);
	ddfs.mouseClicked(callDirectedDfs);
	date = new Date();
	date.setTime(0);
	frameRate(60);
	noStroke();
}

function draw() {
	wSize = windowWidth - wOff;
	hSize = windowHeight - hOff;
	canvas.resize(wSize < wMin ? wMin : wSize , hSize < hMin ? hMin : hSize);
	background(0);

	for(let i=0; i<nodes.length; i++){
		nodes[i].showAdj();
	}
	for(let i=0; i<nodes.length; i++){
		nodes[i].showVert();
	}

	if(mouseIsPressed && moving != -1){
		nodes[moving].move();
	}

	var now = Date.now();

	if(now > timer + speed.value()*100){
		if(dfsOrder.length-dit > 0){

			if(dit < dfsOrder.length-1){
				var offset = 0;
				while(!nodes[dfsOrder[dit-offset]].paintPath(dfsOrder[dit+1])){
					offset++;
				}
				offset=0;
				while(!nodes[dfsOrder[dit+1]].paintPath(dfsOrder[dit-offset])){
					offset++;
				}
			}
			nodes[dfsOrder[dit++]].fillValue = 0;
			timer = Date.now();
		}

		if(bfsOrder.length-bit > 0){
			if(bfsOrder[bit].from != bfsOrder[bit].to){
				nodes[bfsOrder[bit].from].paintPath(bfsOrder[bit].to, bfsColors[bfsOrder[bit].from]);
				nodes[bfsOrder[bit].to].paintPath(bfsOrder[bit].from, bfsColors[bfsOrder[bit].from]);
			}
			nodes[bfsOrder[bit].from].fillValue = 0;
			nodes[bfsOrder[bit++].to].fillValue = 0;
			timer = Date.now();
		}
	}
}


function callBfs(){
	for(let i=0; i<nodes.length; i++){
		nodes[i].reset();
	}
	// var init = floor(random(0, nodes.length));
	var init = 0;
	bfsOrder = [];
	bfsColors = nodes[init].bfs();

	for(let i=0; i<bfsOrder.length; i++){
		console.log(bfsOrder[i]);
	}
	bit = 0;
	timer = Date.now();
}

function callDfs() {
	for(let i=0; i<nodes.length; i++){
		nodes[i].reset();
	}
	var init = floor(random(0, nodes.length));
	// var init = 0;
	dfsOrder = [];
	dfsOrder = nodes[init].dfs();
	dit=0;
	for(let i=0; i<dfsOrder.length; i++){
		console.log(dfsOrder[i]);
	}
	for(let i=0; i<nodes.length; i++){
		nodes[i].visited = false;
	}
	// timer = date.getTime();
	timer = Date.now();
}

function callDirectedDfs(){
	for(let i=0; i<nodes.length; i++){
		nodes[i].reset();
	}
	var init = 0;
	for(let i=0; i<nodes.length; i++){
		if(nodes[i].x < nodes[init].x){
			init = i;
		}
	}
	dfsOrder = [];
	dfsOrder = nodes[init].ddfs();
	dit = 0;
	for(let i=0; i<nodes.length; i++){
		nodes[i].visited = false;
	}

}

function getNodes(){

	for(let i=0; i<csv.data.length-1; i++){
		nodes.push(new Node(csv.data[i]["nodeIndex"], csv.data[i]["nodeX"], csv.data[i]["nodeY"]));
	}

	for(let i=0; i<nodes.length; i++){
		for(let j=1; j<=10; j++){

			if(csv.data[i]["adj"+j] != "-1" && csv.data[i]["adj"+j])
				nodes[i].setAdjacencies(nodes[parseInt(csv.data[i]["adj"+j],10)], csv.data[i]["dist"+j]);
		}
	}

}

function handleFileSelect(evt) {
		var files = evt.target.files;
		for (var i = 0, f; f = files[i]; i++) {
		  var reader = new FileReader();
		  reader.onload = (function(theFile) {
			return function(e) {
				inputFile = e.target.result;
				csv = Papa.parse(inputFile, {header:true});
				getNodes();
			};
		  })(f);
		  reader.readAsText(f);
		}
}

function mousePressed(){
	for(let i=0; i<nodes.length; i++){
		if(nodes[i].clicked()){
			moving = i;
			break;
		}
	}
}

function mouseReleased(){
	moving = -1;
}
