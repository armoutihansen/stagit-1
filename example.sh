#!/bin/sh
# - Makes index for repositories in a single directory.
# - Makes static pages for each repository directory.
#
# NOTE, things to do manually (once):
# - copy style.css, logo.png and favicon.png manually, a style.css example
#   is included.
# - write clone url, for example "git://git.codemadness.org/dir" to the "url"
#   file for each repo.
#
# Usage:
# - mkdir -p htmldir && cd htmldir
# - sh example.sh repo-dir

set -e

reposdir="/var/www/domains/git.codemadness.nl/home/src/"
curdir=$(pwd)

# make index.
cd "${reposdir}"
find . -maxdepth 1 -type d | grep -v "^.$" | sort | xargs urmoms-index > "${curdir}/index.html"

# make files per repo.
find . -maxdepth 1 -type d | grep -v "^.$" | sort | while read -r dir; do
	cd "${reposdir}"
	d=$(basename "${dir}")

	printf "%s..." "${d}"
	cd "${curdir}"
	
	test -d "${d}" || mkdir -p "${d}"
	cd "${d}"
	urmoms "${reposdir}${d}"

	printf " done\n"
done