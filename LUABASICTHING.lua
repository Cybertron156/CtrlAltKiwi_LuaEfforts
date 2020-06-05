--Monobehavior method overrides
function Init()
	print("Init Overridden!");
end
function Update(dt)
	print("Update Overridden! dt: "..dt);
end
function LateUpdate(dt)
	print("Collision resolution and all that fun shit! dt: "..dt);
end
function Exit()
	print("Exit Overridden!");
end
--Just other functions
function foo()
	z = 5;
	print("foo.");
end
function foobar()
	foo();
	return 7, 8;
end