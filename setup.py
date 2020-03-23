from distutils.core import setup, Extension


def main():
    setup(
        name="dynamic_input",
        version="1.0.0",
        description="Python module for dynamic command line input, written in C",
        author="Jan Zarzycki",
        author_email="jzarzycki97@gmail.com",
        ext_modules=[Extension("dynamic_input", ["dynamic_input.c"])],
    )


if __name__ == "__main__":
    main()
