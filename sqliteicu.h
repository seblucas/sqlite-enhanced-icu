<!DOCTYPE html>
<html>
<head>
<base href="http://www.sqlite.org/src/finfo" />
<title>SQLite: File History</title>
<link rel="alternate" type="application/rss+xml" title="RSS Feed"
      href="http://www.sqlite.org/src/timeline.rss">
<link rel="stylesheet" href="/src/style.css/1369751106c2319" type="text/css"
      media="screen">
</head>
<body>
<div class="header">
  <div class="logo">
    <img src="http://www.sqlite.org/src/logo" alt="logo" border="0">
  </div>
  <div class="title"><small>SQLite</small><br>File History</div>
  <div class="status"><nobr>Not logged in</nobr><small><div id="clock"></div></small></div>
</div>
<script>
function updateClock(){
  var e = document.getElementById("clock");
  if(e){
    var d = new Date();
    e.innerHTML=d.toISOString().replace("T"," ").replace(/:\d\d\.\d+Z/,"");
    setTimeout("updateClock();",(60-d.getSeconds())*1000);
  }
}
updateClock();
</script>
<div class="mainmenu"><a href='/'>Home</a><a href='http://www.sqlite.org/src/timeline?y=ci'>Timeline</a><a href='http://www.sqlite.org/src/brlist'>Branches</a><a href='http://www.sqlite.org/src/taglist'>Tags</a><a href='http://www.sqlite.org/src/reportlist'>Tickets</a><a href='http://www.sqlite.org/src/wiki'>Wiki</a><a href='http://www.sqlite.org/src/login'>Login</a></div>
<div class="submenu">
<a class="label" href="/src/finfo?name=ext/icu/sqliteicu.h&amp;fco=0">Full</a>
</div>
<div class="content">
<script>
function gebi(x){
if(/^#/.test(x)) x = x.substr(1);
var e = document.getElementById(x);
if(!e) throw new Error("Expecting element with ID "+x);
else return e;}
</script>
<h2>History of files named ext/icu/sqliteicu.h</h2>
<div id="canvas" style="position:relative;width:1px;height:1px;"
 onclick="clickOnGraph(event)"></div>
<table id="timelineTable" class="timelineTable">
<tr><td>
  <div class="divider">2008-09-08</div>
</td><td></td><td></td></tr>
<tr><td class="timelineTime">
<a id='a1' href='/src/honeypot'>08:08</a></td>
<td class="timelineGraph"><div id="m1"></div></td>
<td class="timelineTableCell">
<b>Added</b>
<a id='a2' href='/src/honeypot'>[728867a802baa5a9]</a> part of check-in
<span class="timelineHistDsp">[79364b963b]</span>
Add header file sqliteicu.h to the ICU extension. This is analogous to the rtree.h and fts3.h headers used by other extensions to declare their entry points. Fix for ticket #3361. (CVS 5680)
 (user:
danielk1977
branch: trunk)
</td></tr>
<tr><td></td><td>
<div id="grbtm" style="width:28px;"></div>
    </td><td></td></tr>
</table>
<script>
var railPitch=18;
var rowinfo = [
{id:1,bg:"",r:0,d:0,mo:0,mu:0,u:-1,f:0,au:[],mi:[],h:"728867a802baa5a9"}];
var nrail = 1
var canvasDiv = gebi("canvas");
var canvasStyle = window.getComputedStyle && window.getComputedStyle(canvasDiv,null);
var lineColor = (canvasStyle && canvasStyle.getPropertyValue('color')) || 'black';
var bgColor = (canvasStyle && canvasStyle.getPropertyValue('background-color')) || 'white';
if( bgColor=='transparent' ) bgColor = 'white';
var boxColor = lineColor;
function drawBox(color,x0,y0,x1,y1){
  var n = document.createElement("div");
  if( x0>x1 ){ var t=x0; x0=x1; x1=t; }
  if( y0>y1 ){ var t=y0; y0=y1; y1=t; }
  var w = x1-x0+1;
  var h = y1-y0+1;
  n.style.position = "absolute";
  n.style.overflow = "hidden";
  n.style.left = x0+"px";
  n.style.top = y0+"px";
  n.style.width = w+"px";
  n.style.height = h+"px";
  n.style.backgroundColor = color;
  canvasDiv.appendChild(n);
  return n;
}
function absoluteY(id){
  var obj = gebi(id);
  if( !obj ) return;
  var top = 0;
  if( obj.offsetParent ){
    do{
      top += obj.offsetTop;
    }while( obj = obj.offsetParent );
  }
  return top;
}
function absoluteX(id){
  var obj = gebi(id);
  if( !obj ) return;
  var left = 0;
  if( obj.offsetParent ){
    do{
      left += obj.offsetLeft;
    }while( obj = obj.offsetParent );
  }
  return left;
}
function drawUpArrow(x,y0,y1){
  drawBox(lineColor,x,y0,x+1,y1);
  if( y0+10>=y1 ){
    drawBox(lineColor,x-1,y0+1,x+2,y0+2);
    drawBox(lineColor,x-2,y0+3,x+3,y0+4);
  }else{
    drawBox(lineColor,x-1,y0+2,x+2,y0+4);
    drawBox(lineColor,x-2,y0+5,x+3,y0+7);
  }
}
function drawThinArrow(y,xFrom,xTo){
  if( xFrom<xTo ){
    drawBox(lineColor,xFrom,y,xTo,y);
    drawBox(lineColor,xTo-3,y-1,xTo-2,y+1);
    drawBox(lineColor,xTo-4,y-2,xTo-4,y+2);
  }else{
    drawBox(lineColor,xTo,y,xFrom,y);
    drawBox(lineColor,xTo+2,y-1,xTo+3,y+1);
    drawBox(lineColor,xTo+4,y-2,xTo+4,y+2);
  }
}
function drawThinLine(x0,y0,x1,y1){
  drawBox(lineColor,x0,y0,x1,y1);
}
function drawNodeBox(color,x0,y0,x1,y1){
  drawBox(color,x0,y0,x1,y1).style.cursor = "pointer";
}
function drawNode(p, left, btm){
  drawNodeBox(boxColor,p.x-5,p.y-5,p.x+6,p.y+6);
  drawNodeBox(p.bg||bgColor,p.x-4,p.y-4,p.x+5,p.y+5);
  if( p.u>0 ) drawUpArrow(p.x, rowinfo[p.u-1].y+6, p.y-5);
  if( p.f&1 ) drawNodeBox(boxColor,p.x-1,p.y-1,p.x+2,p.y+2);
  if( p.u==0 ) drawUpArrow(p.x, 0, p.y-5);
  if( p.d ) drawUpArrow(p.x, p.y+6, btm);
  if( p.mo>0 ){
    var x1 = p.mo + left - 1;
    var y1 = p.y-3;
    var x0 = x1>p.x ? p.x+7 : p.x-6;
    var u = rowinfo[p.mu-1];
    var y0 = u.y+5;
    if( x1>=p.x-5 && x1<=p.x+5 ){
      y1 = p.y-5;
    }else{
      drawThinLine(x0,y1,x1,y1);
    }
    drawThinLine(x1,y0,x1,y1);
  }
  var n = p.au.length;
  for(var i=0; i<n; i+=2){
    var x1 = p.au[i]*railPitch + left;
    var x0 = x1>p.x ? p.x+7 : p.x-6;
    var u = rowinfo[p.au[i+1]-1];
    if(u.id<p.id){
      drawBox(lineColor,x0,p.y,x1,p.y+1);
      drawUpArrow(x1, u.y+6, p.y);
    }else{
      drawBox("#600000",x0,p.y,x1,p.y+1);
      drawBox("#600000",x1-1,p.y,x1,u.y+1);
      drawBox("#600000",x1,u.y,u.x-6,u.y+1);
      drawBox("#600000",u.x-9,u.y-1,u.x-8,u.y+2);
      drawBox("#600000",u.x-11,u.y-2,u.x-10,u.y+3);
    }
  }
  for(var j in p.mi){
    var y0 = p.y+5;
    var mx = p.mi[j];
    if( mx<0 ){
      mx = left-mx;
      drawThinLine(mx,y0,mx,btm);
    }else{
      mx += left;
    }
    if( mx>p.x ){
      drawThinArrow(y0,mx,p.x+6);
    }else{
      drawThinArrow(y0,mx,p.x-5);
    }
  }
}
var selBox = null;
var selRow = null;
function renderGraph(){
  var canvasDiv = gebi("canvas");
  while( canvasDiv.hasChildNodes() ){
    canvasDiv.removeChild(canvasDiv.firstChild);
  }
  var canvasY = absoluteY("timelineTable");
  var left = absoluteX("m"+rowinfo[0].id) - absoluteX("canvas") + 15;
  for(var i in rowinfo){
    rowinfo[i].y = absoluteY("m"+rowinfo[i].id) + 10 - canvasY;
    rowinfo[i].x = left + rowinfo[i].r*railPitch;
  }
  var btm = absoluteY("grbtm") + 10 - canvasY;
  for(var i in rowinfo){
    drawNode(rowinfo[i], left, btm);
  }
  if( selRow!=null ) clickOnRow(selRow);
}
function clickOnGraph(event){
  var x=event.clientX-absoluteX("canvas");
  var y=event.clientY-absoluteY("canvas");
  if(window.pageXOffset!=null){
    x += window.pageXOffset;
    y += window.pageYOffset;
  }else{
    var d = window.document.documentElement;
    if(document.compatMode!="CSS1Compat") d = d.body;
    x += d.scrollLeft;
    y += d.scrollTop;
  }
  for(var i in rowinfo){
    p = rowinfo[i];
    if( p.y<y-11 ) continue;
    if( p.y>y+9 ) break;
    if( p.x>x-11 && p.x<x+9 ){
      clickOnRow(p);
      break;
    }
  }
}
function clickOnRow(p){
  if( selRow==null ){
    selBox = drawBox("red",p.x-2,p.y-2,p.x+3,p.y+3);
    selRow = p;
  }else if( selRow==p ){
    var canvasDiv = gebi("canvas");
    canvasDiv.removeChild(selBox);
    selBox = null;
    selRow = null;
  }else{
    location.href="/src/fdiff?v1="+selRow.h+"&v2="+p.h+"&sbs=1";
  }
}
var lastId = "m"+rowinfo[rowinfo.length-1].id;
var lastY = 0;
function checkHeight(){
  var h = absoluteY(lastId);
  if( h!=lastY ){
    renderGraph();
    lastY = h;
  }
  setTimeout("checkHeight();", 1000);
}
checkHeight();
</script>
</div>
<div class="footer">
This page was generated in about 
0.006s by
Fossil version 1.28 [c23190a61d] 2014-04-03 07:05:17
</div>
</body></html>
