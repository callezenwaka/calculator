from setuptools import setup, find_packages
from pathlib import Path

setup(
    name="syft-theme",
    url="https://syft-theme.readthedocs.io",
    project_urls={
        "Documentation": "https://openmined.org",
        "Source Code": "https://github.com/callezenwaka/syft-theme",
        "Bug Tracker": "https://github.com/callezenwaka/syft-theme/issues",
    },
    author="Callis Ezenwaka",
    author_email="callis@openmined.org",
    classifiers=[
        "Development Status :: 3 - Alpha",
        "Environment :: Web Environment",
        "Intended Audience :: Developers",
        "License :: OSI Approved :: Apache Software License",
        "Operating System :: OS Independent",
        "Programming Language :: Python",
        "Programming Language :: Python :: 3",
        "Topic :: Internet",
        "Topic :: Software Development :: Documentation",
    ],
    license="Apache 2.0",
    description="The Syft Documentation Theme",
    long_description=Path("./README.md").read_text(),
    long_description_content_type="text/markdown",
    keywords="syft, sphinx, theme, jupyter, notebook",
    zip_safe=True,
    include_package_data=True,
    install_requires=[
        "sphinx-book-theme>=0.1.7,<0.2",
    ],
    packages=find_packages(),
    entry_points={"sphinx.html_themes": ["syft_theme = syft_theme"]},
    use_scm_version={"version_scheme": "post-release", "local_scheme": "dirty-tag"},
)
