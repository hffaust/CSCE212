.data
str: .asciiz "The quick brown fox jumps over the lazy dog."

.text
.globl main
main:
  la  $s0 str

  ori $v0 $0 4 # string print mode
  # Print the whole string
  or  $a0 $0 $s0
  syscall
  jal printnewl

  # Print the string without it's first character (first byte)
  addiu $a0 $a0 1
  syscall
  jal printnewl

  addiu $a0 $a0 4
  syscall
  jal printnewl

  # Finish execution
  # (otherwise this bleeds back into `printnewl')
  j end

printnewl:
  # push $v0 and $a0 to the stack
  addiu $sp $sp -4
  sw $a0 0($sp) # push a0
  addiu $sp $sp -4
  sw $v0 0($sp) # push v0

  ori $v0 $0 11
  ori $a0 $0 10
  syscall

  # restore $v0 and $a0 from the stack
  lw $v0 0($sp) # restore v0
  addiu $sp $sp 4
  lw $a0 0($sp) # restore a0
  addiu $sp $sp 4

  # jump to the return address
  j $ra

end:
  ori $v0 $0 10
  syscall
