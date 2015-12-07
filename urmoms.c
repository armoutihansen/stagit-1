#include <unistd.h>
	fputs("</head>\n<body>\n<center>\n", fp);
	fprintf(fp, "<h1><img src=\"%slogo.png\" alt=\"\" width=\"32\" height=\"32\" /> %s <span class=\"desc\">%s</span></h1>\n",
	fputs("\n</center>\n<hr/>\n<pre>", fp);
	const char *msg;
	fprintf(fp, "<b>commit</b> <a href=\"%scommit/%s.html\">%s</a>\n",
	if (git_oid_tostr(buf, sizeof(buf), git_commit_parent_id(commit, 0)) && buf[0])
		fprintf(fp, "<b>parent</b> <a href=\"%scommit/%s.html\">%s</a>\n",
		fprintf(fp, "<b>Merge:</b>");
		for (i = 0; i < count; i++) {
		fprintf(fp, "<b>Author:</b> ");
		fputs("</a>&gt;\n<b>Date:</b>   ", fp);
	if ((msg = git_commit_message(commit)))
		xmlencode(fp, msg, strlen(msg));
	/* check if file exists if so skip it */
	if (!access(path, F_OK))
		return;
	fp = efopen(path, "w+b");
	if (!(error = git_commit_parent(&parent, commit, 0))) {
		if ((error = git_commit_tree(&parent_tree, parent)))
			goto err; /* TODO: handle error */
	} else {
		parent = NULL;
		parent_tree = NULL;
	}
	if ((error = git_diff_tree_to_tree(&diff, repo, parent_tree, commit_tree, NULL)))
			fprintf(fp, "<b>Diffstat:</b>\n");
		fprintf(fp, "<b>diff --git a/<a href=\"%sfile/%s\">%s</a> b/<a href=\"%sfile/%s\">%s</a></b>\n",
		/* TODO: "new file mode <mode>". */
		/* TODO: add indexfrom...indexto + flags */

		fputs("<b>--- ", fp);
		if (delta->status & GIT_DELTA_ADDED)
			fputs("/dev/null", fp);
		else
			fprintf(fp, "a/<a href=\"%sfile/%s\">%s</a>",
				relpath, delta->old_file.path, delta->old_file.path);

		fputs("\n+++ ", fp);
		if (delta->status & GIT_DELTA_DELETED)
			fputs("/dev/null", fp);
		else
			fprintf(fp, "b/<a href=\"%sfile/%s\">%s</a>",
				relpath, delta->new_file.path, delta->new_file.path);
		fputs("</b>\n", fp);
		/* check binary data */
		if (delta->flags & GIT_DIFF_FLAG_BINARY) {
			fputs("Binary files differ\n", fp);
			git_patch_free(patch);
			continue;
		}

			fprintf(fp, "<span class=\"h\">%s</span>\n", hunk->header);
	int error, ret = 0;
	i = 0; /* DEBUG: to limit commits */
	fputs("<table><thead>\n<tr><td>Commit message</td><td>Author</td><td align=\"right\">Age</td>"
	      "<td align=\"right\">Files</td><td align=\"right\">+</td><td align=\"right\">-</td></tr>\n</thead><tbody>\n", fp);
		/* DEBUG */
/*		if (i++ > 100)
			break;*/
		relpath = "";

		if (git_commit_lookup(&commit, repo, &id)) {
			ret = 1;
			goto err;
		}
			goto errdiff; /* TODO: handle error */
		if (!(error = git_commit_parent(&parent, commit, 0))) {
			if ((error = git_commit_tree(&parent_tree, parent)))
				goto errdiff; /* TODO: handle error */
		} else {
			parent = NULL;
			parent_tree = NULL;
		}

		if ((error = git_diff_tree_to_tree(&diff, repo, parent_tree, commit_tree, NULL)))
		fputs("</td></tr>\n", fp);
		relpath = "../";
errdiff:
err:
	relpath = "";
	return ret;
	const char *msg, *summary;
	if (git_oid_tostr(buf, sizeof(buf), git_commit_parent_id(commit, 0)) && buf[0])
		for (i = 0; i < count; i++) {
	if ((msg = git_commit_message(commit)))
		xmlencode(fp, msg, strlen(msg));
	fputs("\n</content>\n", fp);
	/* check LICENSE */
	haslicense = !git_revparse_single(&obj, repo, "HEAD:LICENSE");
	/* check README */
	hasreadme = !git_revparse_single(&obj, repo, "HEAD:README");