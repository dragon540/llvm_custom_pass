define i32 @func(i32 %arg1, i64 %arg2) {
	%c = add i64 5, %arg2
	%d = sub i64 9, 7
	%e = add i32 %arg1, %arg1

	ret i32 %arg1
}
