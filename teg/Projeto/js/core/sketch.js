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
let moving = -1;
let nodes = [];
let dfsOrder = [];
let paintOrder = [];
let it=0;

function setup() {
	size = createSlider(3, 100, 25);
	canvas = createCanvas(windowWidth - wOff, windowHeight - hOff);
	canvas.position((windowWidth - width) / 2,(windowHeight - height) / 2);
	bfs = createButton('BFS');
	dfs = createButton('DFS');
	ddfs = createButton('DDFS');
	bfs.position(64, 36);
	dfs.position(104, 36);
	ddfs.position(144, 36);
	dfs.mouseClicked(callDfs);
	ddfs.mouseClicked(callDirectedDfs);
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
		frameRate(2);
		if(it < dfsOrder.length-1){
			var offset = 0;
			while(!nodes[dfsOrder[it-offset]].paintPath(dfsOrder[it+1])){
				offset++;
			}
			offset=0;
			while(!nodes[dfsOrder[it+1]].paintPath(dfsOrder[it-offset])){
				offset++;
			}
		}
		console.log(it);
		nodes[dfsOrder[it++]].fillValue = 0;
	}else{
		frameRate(60);
	}
}

function callDfs() {
	// var init = floor(random(0, nodes.length));
	var init = 0;
	dfsOrder = [];
	dfsOrder = nodes[init].dfs();
	it=0;
	for(let i=0; i<dfsOrder.length; i++){
		console.log(dfsOrder[i]);
	}
	for(let i=0; i<nodes.length; i++){
		nodes[i].visited = false;
	}
}

function callDirectedDfs(){
	var init = 0;
	for(let i=0; i<nodes.length; i++){
		if(nodes[i].x < nodes[init].x){
			init = i;
		}
	}
	dfsOrder = [];
	dfsOrder = nodes[init].ddfs();
	it = 0;
	for(let i=0; i<nodes.length; i++){
		nodes[i].visited = false;
	}

	// paintOrder = [[]];
	//
	// for(let i=0; i<dfsOrder.size()-1; i++){
	// 	paintOrder = concat(paintOrder, [dfsOrder[i], dfsOrder[i+1]]);
	// }

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
