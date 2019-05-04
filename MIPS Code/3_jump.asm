.text
.globl main

main:
  addiu $s0 $0 0
  j main
  addiu $s0 $0 1 # This line will never execute
