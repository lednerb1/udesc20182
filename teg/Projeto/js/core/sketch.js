let canvas;
let bfs;
let dfs;
let wOff = 128;
let hOff = 72;
let wMin = 256;
let hMin = 144;
let wSize;
let hSize;
let inputFile;
let csv;
let size;
let moving = -1;
let nodes = [];
let dfsOrder = [];
let it=0;

function setup() {
	size = createSlider(3, 100, 25);
	canvas = createCanvas(windowWidth - wOff, windowHeight - hOff);
	canvas.position((windowWidth - width) / 2,(windowHeight - height) / 2);
	bfs = createButton('BFS');
	dfs = createButton('DFS');
	bfs.position(64, 36);
	dfs.position(104, 36);
	dfs.mouseClicked(callDfs);
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

	if(dfsOrder.length-it > 0){
		frameRate(10);
		nodes[dfsOrder[it++]].fillValue = 120;
	}else{
		frameRate(60);
	}
}

function callDfs() {
	var init = floor(random(0, nodes.length));
	console.log(init);
	dfsOrder = nodes[init].dfs();
	it=0;
	for(let i=0; i<nodes.length; i++){
		nodes[i].visited = false;
	}
}

function getNodes(){

	for(let i=0; i<csv.data.length-1; i++){
		console.log(csv.data[i]["nodeIndex"] + " " + csv.data[i]["nodeX"] + " " + csv.data[i]["nodeY"]);
		console.log(csv.data[i]["adj1"] + " " + csv.data[i]["adj2"] + " " + csv.data[i]["adj3"]);
		nodes.push(new Node(csv.data[i]["nodeIndex"], csv.data[i]["nodeX"], csv.data[i]["nodeY"]));
	}

	for(let i=0; i<nodes.length; i++){
		if(csv.data[i]["adj1"] != "")
			nodes[i].setAdjacencies(nodes[parseInt(csv.data[i]["adj1"],10)], csv.data[i]["dist1"]);
		if(csv.data[i]["adj2"] != "")
			nodes[i].setAdjacencies(nodes[parseInt(csv.data[i]["adj2"],10)], csv.data[i]["dist2"]);
		if(csv.data[i]["adj3"] != "")
			nodes[i].setAdjacencies(nodes[parseInt(csv.data[i]["adj3"],10)], csv.data[i]["dist3"]);
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

function sleepFor( sleepDuration ){
    var now = new Date().getTime();
    while(new Date().getTime() < now + sleepDuration){ /* do nothing */ }
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
