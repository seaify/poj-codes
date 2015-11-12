{$apptype console}
{$q+,r+}
uses
    math;
const
    max_n = 200;
    max_m = 10000;
var
    i, n, m, k: longint;
    a: array [1..max_n, 1..max_n] of longint;
    cl, cr, fl, fr, pl, pr: array [1..max_n] of longint;
    b, e: longint;
    q: array [1..max_n * 2] of longint;
    h, t: longint;
    v: longint;
    f: boolean;

function filll(v, mf: longint): longint; forward;

function fillr(v, mf: longint): longint;
begin
    result := filll(pr[v], mf);
    a[pr[v]][v] := a[pr[v]][v] + result;
end;

function filll(v, mf: longint): longint;
begin
    if pl[v] = -1 then begin
        result := min(mf, cl[v] - fl[v]);
        fl[v] := fl[v] + result;
    end else begin
        result := fillr(pl[v], min(mf, a[v][pl[v]]));
        a[v][pl[v]] := a[v][pl[v]] - result;
    end;
end;

begin
    assign(input, 'destroy.in'); reset(input);
    assign(output, 'destroy.out'); rewrite(output);

    read(n, m);

    for i := 1 to n do begin
        read(cr[i]);
        fl[i] := 0;
    end;

    for i := 1 to n do begin
        read(cl[i]);
        fr[i] := 0;
    end;

    fillchar(a, sizeof(a), $ff);
    for i := 1 to m do begin
        read(b, e);
        a[b][e] := 0;
    end;

    f := true;
    while f do begin
        fillchar(q, sizeof(q), 0);

        f := false;
        fillchar(pl, sizeof(pl), 0);
        fillchar(pr, sizeof(pr), 0);
        t := 0;
        h := 0;
        for i := 1 to n do begin
            if fl[i] <> cl[i] then begin
                inc(t);
                q[t] := i;
                pl[i] := -1;
            end;
        end;

        while h < t do begin
            inc(h);
            v := abs(q[h]);
            if q[h] > 0 then begin
                for i := 1 to n do begin
                    if (a[v][i] >= 0) and (pr[i] = 0) then begin
                        inc(t);
                        q[t] := -i;
                        pr[i] := v;
                    end;
                end;
            end else begin
                for i := 1 to n do begin
                    if (a[i][v] > 0) and (pl[i] = 0) then begin
                        inc(t);
                        q[t] := i;
                        pl[i] := v;
                    end;
                end;
            end;
        end;

        for i := 1 to n do begin
            if (pr[i] <> 0) and (fr[i] <> cr[i]) then begin
                fr[i] := fr[i] + fillr(i, cr[i] - fr[i]);
                f := true;
            end;
        end;
    end;

    k := 0;
    m := 0;
    for i := 1 to n do begin
        if pl[i] = 0 then begin
            inc(k, cl[i]);
            inc(m);
        end;
        if pr[i] <> 0 then begin
            inc(m);
            inc(k, cr[i]);
        end;
    end;

    writeln(k);
    writeln(m);

    for i := 1 to n do begin
        if pl[i] = 0 then begin
            writeln(i, ' -');
        end;
        if pr[i] <> 0 then begin
            writeln(i, ' +');
        end;
    end;

    close(input);
    close(output);
end.