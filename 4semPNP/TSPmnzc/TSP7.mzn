include "all_different.mzn";
int: n;
array[1..n, 1..n] of int: dist;
int: start_city;
int: end_city;

array[1..n] of var 1..n: city;

constraint city[1] = start_city;
constraint city[n] = end_city;
constraint all_different(city);

var int: total_distance = sum(i in 2..n)(dist[city[i-1],city[i]]);
solve minimize total_distance;

output["total: " ++ show(total_distance / 1000) ++ "\n"];