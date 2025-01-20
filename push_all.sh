#!/bin/bash

# Ensure the script stops if any command fails
set -e

# Push changes in each submodule
echo "Pushing changes in submodules..."
git submodule foreach --recursive '
  echo "Entering submodule: $name"
  branch=$(git symbolic-ref --short HEAD || echo "detached")
  if [ "$branch" = "detached" ]; then
    echo "Submodule $name is in a detached HEAD state. Please fix manually."
    exit 1
  fi
  git add .
  git commit -m "Update in submodule: $name" || echo "No changes to commit in $name."
  git push origin $branch
'

# Go back to the root of the parent repository
echo "Pushing changes in parent repository..."
cd "$(git rev-parse --show-toplevel)"
git add .
git commit -m "Update submodule references and parent repository" || echo "No changes to commit in parent repository."
git push

echo "All changes pushed successfully!"
