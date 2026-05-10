.PHONY: building deps cottontail checking FORCE

building: FORCE
	python -m pip install -v --no-build-isolation -e .

deps: FORCE
	python -m pip install scikit-build-core pybind11 cmake

cottontail: FORCE
	$(MAKE) -C ../Cottontail building

checking: FORCE
	python -c "import meadowlark as lark; print(lark.maxfinity)"
	ldd meadowlark/_meadowlark*.so

FORCE:
