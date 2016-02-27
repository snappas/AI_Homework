connect(a,b,5).
connect(a,c,8).
connect(a,d,10).
connect(b,d,2).
connect(b,e,9).
connect(c,f,5).
connect(c,d,4).
connect(d,f,11).
connect(d,g,4).
connect(d,e,6).
connect(e,g,2).

connected(X,Y,L) :- connect(X,Y,L) ; connect(Y,X,L).
