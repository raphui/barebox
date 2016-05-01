	.section .piggydata,#alloc
	.globl  input_data
input_data:
	.incbin "arch/arm64/pbl/piggy.gzip"
	.globl  input_data_end
input_data_end:
