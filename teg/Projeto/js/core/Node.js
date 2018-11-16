class Node {
  constructor(a,b,c){
    this.label = parseInt(a,10);
    this.x = map(b, 0, 1, 50, width-50);
    this.y = map(c, 0, 1, 50, height-50);
    this.adj = [];
    this.visited = false;
    this.fillValue = 255;
  }

  showAdj(){
    push();
    stroke(255);
    strokeWeight(5);
    for(let i=0; i<this.adj.length; i++){
      line(this.x, this.y, this.adj[i].o.x, this.adj[i].o.y);
    }
    pop();
  }

  showVert(){
    push();
    fill(this.fillValue, 128, 56);
    ellipse(this.x, this.y, size.value());
    fill(0);
    textSize(size.value()/2);
    textAlign(CENTER);
    text(this.label, this.x, this.y+8);
    pop();
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
    this.adj.push({o:otherNode, d:otherDist});
  }

  dfs(){
    let order = []
    order.push(this.label);
    this.fillValue = 255;
    this.visited = true;
    for(let i=0; i<this.adj.length; i++){
      if(this.adj[i].o.visited == false){
        console.log(this.adj[i].o.label);
        order = concat(order, this.adj[i].o.dfs());
      }
    }
    return order;
  }
}
