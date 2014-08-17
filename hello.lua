athelia = require("athelia")

a = athelia.Vector();
a.x = 1;
a.y = 2;
a.z = 3;
b = athelia.Vector();
b.x = 3;
b.y = 2;
b.z = 1;

c = a*2
d = a+b
e = a:dot(b)
f = a:cross(b)
g = a:size()
h = a:magnitude()

print(c.x)
print(d.x)
print(e)
print(f.x)
print(g)
print(h)
