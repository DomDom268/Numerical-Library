include makefiles/Vector/basic.mk
include makefiles/Vector/math.mk
include makefiles/Vector/edge.mk
include makefiles/Vector/create.mk
include makefiles/Vector/setval.mk
include makefiles/Vector/add.mk
include makefiles/Vector/sub.mk
include makefiles/Vector/dot.mk
include makefiles/Vector/scale.mk
include makefiles/Vector/eucdist.mk
include makefiles/Vector/eucnorm.mk
include makefiles/Vector/mannorm.mk
include makefiles/Vector/print.mk
include makefiles/Vector/normbench.mk
include makefiles/Vector/comprehensive.mk
include makefiles/Matrix/basic.mk
include makefiles/Matrix/math.mk
include makefiles/Matrix/edge.mk
include makefiles/Matrix/add.mk
include makefiles/Matrix/create.mk
include makefiles/Matrix/elm.mk
include makefiles/Matrix/getVal.mk
include makefiles/Matrix/id.mk
include makefiles/Matrix/multiply.mk
include makefiles/Matrix/scalar.mk
include makefiles/Matrix/setVal.mk
include makefiles/Matrix/sub.mk
include makefiles/Matrix/transpose.mk
include makefiles/Vector/asan.mk
include makefiles/Vector/ubsan.mk
include makefiles/Matrix/asan.mk
include makefiles/Matrix/ubsan.mk

clean:
	rm -f *.exe
