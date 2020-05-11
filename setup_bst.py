from distutils.core import setup, Extension

module1 = Extension(
	'bst', # название модуля внутри Python
	 sources = ['binary_search_tree.c'] # Исходные файлы модуля
)

setup(
	name = 'bst',              # название модуля (my_plus.__name__)
	version = '1.1',               # версия модуля
	description = 'Simple module', # описание модуля
	ext_modules= [module1]         # объекты типа Extension (мы объявили его выше)
)
