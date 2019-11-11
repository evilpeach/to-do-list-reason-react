let rec pushback = (e, ls) =>
  switch (ls) {
  | [] => [e]
  | [x, ...xs] => [x, ...pushback(e, xs)]
  };

let rec filter = (f, ls) =>
  switch (ls) {
  | [] => []
  | [x, ...xs] => f(x) ? [x, ...filter(f, xs)] : filter(f, xs)
  };

let rec map = (ls, f) =>
  switch (ls) {
  | [] => []
  | [x, ...rest] => [f(x), ...map(rest, f)]
  };
