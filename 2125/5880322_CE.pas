{$Q+,R+,O-}
program macro;
const MaxN=100;  MaxM=4000;  MaxW=1000000;  MaxN1=2*MaxN+2;
var
  A  : array [1..MaxN1, 1..MaxN1] of integer;
  F  : array [1..MaxN1] of boolean;
  N, M, s0, N1, W, S  : integer;

function rec (u : integer) : boolean;
var v : integer;
begin
  F[u] := true;  rec := true;  if u = N1 then exit;
  for v := 1 to N1 do 
    if (A[u,v] >= W) and not F[v] and rec (v) then begin
      dec (A[u,v], W);  inc (A[v,u], W);  exit
    end;
  rec := false
end;

var i, u, v : integer;
begin
  assign (input, 'destroy.in');  reset (input);
  assign (output, 'destroy.out');  rewrite (output);
  read (N, M);
  if (N <= 0) or (N > MaxN) or (M <= 0) or (M > MaxM) then runerror (239);
  s0 := 2 * N + 1;  N1 := s0 + 1;
  for i := 1 to N do begin
    read (W);  if (W <= 0) or (W > MaxW) then runerror (239);
    A[N+i, N1] := W;
  end;
  for i := 1 to N do begin
    read (W);  if (W <= 0) or (W > MaxW) then runerror (239);
    A[s0, i] := W
  end;
  for i := 1 to M do begin
    read (u, v);  
    if (u <= 0) or (v <= 0) or (u > MaxN) or (v > MaxN) then runerror (239);
    A[u, N+v] := MaxW+1;
  end;
  W := MaxW;  S := 0;
  repeat
    fillchar (F, sizeof(F), 0);
    if rec(s0) then inc (S, W) else W := W shr 1
  until W = 0;
  writeln (S);
  u := 0;
  for i := 1 to N do inc (u, ord (not F[i]) + ord (F[N+i]));
  writeln (u);
  for i := 1 to N do if not F[i] then writeln (i, ' -');
  for i := 1 to N do if F[N+i] then writeln (i, ' +')
end.
