define i32 @foofunc(i32 %a, i32 %b, i32 %c) {
	%d = sub i32 7, 5
	%e = sub i32 2, 1
	%f = sub i32 %b, %d
	%g = sub i32 %c, 2
	%h = add i32 %f, 3

	ret i32 %g
}
