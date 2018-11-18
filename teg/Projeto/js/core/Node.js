class Node {
  constructor(a,b,c){
    this.label = parseInt(a,10);
    this.x = map(b, 0, 1, 50, width-50);
    this.y = map(c, 0, 1, 50, height-50);
    this.adj = [];
    this.visited = false;
    this.fillValue = 255;
    Node.strkw = 5-Math.log10(nodes.length);
  }

  showAdj(){
    push();
    strokeWeight(Node.strkw);
    for(let i=0; i<this.adj.length; i++){
      stroke(this.adj[i].c[0], this.adj[i].c[1], this.adj[i].c[2]);
      line(this.x, this.y, this.adj[i].o.x, this.adj[i].o.y);
      var m = (this.adj[i].o.y - this.y) / (this.adj[i].o.x - this.x);
      var x = (this.adj[i].o.x + this.x) / 2;
      var y = m*x - m*this.x + this.y;
      push();
      noStroke();
      fill(128);
      textSize(size.value()/3);
      text(this.adj[i].d, x, y);
      pop()
    }
    pop();
  }

  showVert(){
    push();
    fill(this.fillValue, map(this.x, 0, width, 100, 255), map(this.y, 0, height, 100, 255));
    ellipse(this.x, this.y, size.value());
    fill(0);
    textSize(size.value()/2);
    textAlign(CENTER);
    text(this.label, this.x, this.y+8);
    pop();
  }

  reset(){
    for(let i=0; i<this.adj.length; i++){
      this.adj[i].c = [255,255,255];
    }
    this.showAdj();
  }

  clicked() {
    var d = dist(mouseX, mouseY, this.x, this.y);
    if(d < size.value() / 4){
      return true;
    }
    return false;
  }

  move() {
    this.x = mouseX;
    this.y = mouseY;
  }

  setAdjacencies(otherNode, otherDist){
    this.adj.push({o:otherNode, d:otherDist, c:[255,255,255]});
  }

  paintPath(next){
    for (let i=0; i<this.adj.length; i++){
      if(this.adj[i].o.label == next){
        this.adj[i].c = [0,0,255];
        return true;
      }
    }
    return false;
  }

  paintPath(next, col){
    for (let i=0; i<this.adj.length; i++){
      if(this.adj[i].o.label == next){
        this.adj[i].c = col;
        return true;
      }
    }
    return false;
  }

  dfs(){
    let order = []
    order.push(this.label);
    this.fillValue = 255;
    this.visited = true;
    for(let i=0; i<this.adj.length; i++){
      if(this.adj[i].o.visited == false){
        // console.log(this.adj[i].o.label);
        order = concat(order, this.adj[i].o.dfs());
      }
    }
    return order;
  }

  ddfs(){
    let order = []
    order.push(this.label);
    this.fillValue = 255;
    this.visited = true;
    for(let i=0; i<this.adj.length; i++){
      if(this.adj[i].o.visited == false && this.x < this.adj[i].o.x){
        console.log(this.label + " -> " + this.adj[i].o.label);
        order = concat(order, this.adj[i].o.ddfs());
      }
    }
    return order;
  }

  bfs() {
    let pat = [ [255, 255, 255] , [0, 0, 255] , [100, 100, 255] , [200, 200, 255] ,
            [200, 255, 200] , [100, 255, 100] , [0, 255, 0] , [0, 100, 0] ,
            [255, 0, 0] , [255 , 100, 100] , [255, 200, 200]  ];
    let dis = [];
    let col = [];
    for(let i=0; i < nodes.length; i++){
      dis[i] = 1;
      col[i] = 0;
    }
    dis[this.label] = 0;
    let queue = [];
    queue.push([this.label, this.label]);
    let elementsToIncrease=1;
    let nextElementsToIncrease=0;
    let depth=1;

    while(queue.length > 0){
      let uu = queue.shift();
      let u = uu[1]
      dis[u] = 0;
      col[u] = pat[depth];
      bfsOrder = concat(bfsOrder, {from:uu[0], to:nodes[u].label});
      nextElementsToIncrease += nodes[u].adj.length;
      --elementsToIncrease;
      if(elementsToIncrease == 0){
        depth++;
        elementsToIncrease = nextElementsToIncrease;
        nextElementsToIncrease = 0;
      }

      for(let i=0; i < nodes[u].adj.length; i++){
        let next = nodes[u].adj[i];
        let v = next.o;
        if(dis[v.label]){
          dis[v.label] = 0;
          queue.push([u, v.label]);
        }
      }
    }

    for(let i=0; i<col.length; i++){
      console.log(i + " " + col[i]);
    }

    return col;

  }


}
