; ModuleID = '../example/ex.ll'
source_filename = "../example/ex.ll"

define i32 @fun() {
  %a = add i32 4, 7
  %c = add i32 %a, 3
  ret i32 %a
}
