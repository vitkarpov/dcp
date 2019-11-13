/**
 * @param {number[][]} points
 * @return {number}
 */
var maxPoints = function(points) {
  if (!points.length) {
    return 0;
  }

  let ans = 1;

  for (let i = 0; i < points.length - 1; i++) {
    const slopes = new Map();
    const p1 = points[i];
    let overlaps = 1;

    for (let j = i + 1; j < points.length; j++) {
      const p2 = points[j];

      if (p1[0] == p2[0] && p1[1] == p2[1]) {
        overlaps++;
      } else {
        const key = hashSlope(p1, p2);
        const val = slopes.get(key);

        slopes.set(key, val ? val + 1 : 1);
      }
    }
    ans = Math.max(ans, overlaps);
    for (const [k, v] of slopes) {
      ans = Math.max(ans, v + overlaps);
    }
  }
  return ans;
};

function hashSlope(p1, p2) {
  let dx = p2[0] - p1[0];
  let dy = p2[1] - p1[1];

  if (dx == 0) {
    return "0";
  }
  if (dy == 0) {
    return "1";
  }

  const sign = (dx > 0) ^ (dy > 0) ? "-" : "+";
  dx = Math.abs(dx);
  dy = Math.abs(dy);

  const d = gcd(dx, dy);

  return `${sign}${Math.abs(dx / d)}/${Math.abs(dy / d)}`;
}

function gcd(x, y) {
  while (y > 0) {
    const tmp = y;
    y = x % y;
    x = tmp;
  }
  return x;
}
