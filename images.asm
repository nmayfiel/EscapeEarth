bits 32 			; this is 32 bit assembly code

section .rodata 		; read only section

    ;; global varaibles to acces in our program
global _image_one_start
global _image_one_size
global _image_two_start
global _image_two_size
global _image_three_start
global _image_three_size
global _image_four_start
global _image_four_size
global _image_five_start
global _image_five_size

_image_one_start:   incbin "Assets/Art/Background/Chapter1_Background.png" ; include bin
_image_one_size:    dd $-_image_one_start ; pos - image_one_start pos
_image_two_start: incbin "Assets/Art/Background/Chapter2_Background.png"
_image_two_size:    dd $-_image_two_start
_image_three_start: incbin "Assets/Art/Background/Chapter3_Background.png"
_image_three_size:    dd $-_image_three_start
_image_four_start: incbin "Assets/Art/Player/wingplane.png"
_image_four_size:   dd $-_image_four_start
_image_five_start: incbin "Assets/Art/Bullet/bullet_wingplane.png"
_image_five_size:   dd $-_image_five_start
