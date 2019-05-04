.text
.globl main

main:
  addi $v0 $0 1       # loads 1 to v0
  addi $v1 $0 5       # loads 5 to v1
  xor $s0,$v0,$v1  # xors v0 and v1 and stores to s0

  addi $s1 $0 10

  addi $t0 $0 -1
