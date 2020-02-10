all:
	gcc *c libft/libft.a minilibx_macos/libmlx.a -framework OpenGL -framework AppKit
	./a.out test_maps/elem.fdf


