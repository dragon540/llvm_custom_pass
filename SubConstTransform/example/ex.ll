define i32 @fun() {
	%a = add i32 4, 7
	%b = sub i32 4, 1
	%c = add i32 %a, %b
	ret i32 %a
}
