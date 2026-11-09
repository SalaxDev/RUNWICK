# Security Policy

## Supported Versions

| Version | Supported |
| - | - |
| [0.1.0] | ✅        |

## Reporting a Vulnerability

Please **do not** open a public issue for security problems.

Report privately via [GitHub Security Advisories](../../security/advisories/new)

Please include: affected version, OS, steps to reproduce, and a sample
input file if the issue involves parsing.

## What to Expect

- Acknowledgment within [7] days.
- I'll confirm whether it's in scope and give a rough timeline.
- Fixes are released as a patch version; you'll be credited unless you
  prefer otherwise.

## Scope

In scope:
- Crashes, memory corruption, or code execution caused by opening a
  malicious/crafted file.
- Local privilege escalation or unsafe temp-file handling.

Out of scope:
- Issues requiring an already-compromised machine or physical access.
- Vulnerabilities in unsupported versions.
- Social engineering, or "malware can modify the config file."
- Reports that only say "this library version is old" without a
  demonstrated impact.

## Release Verification

Release binaries are **not code-signed**. Trust for a download comes from:

- Downloading only from this repository's Releases page (HTTPS).
- [If using CI attestations:] Verifying build provenance:
  `gh attestation verify <file> --repo <owner>/<repo>`

Checksums protect against corrupted or tampered downloads from mirrors;
they are not a defense against compromise of this repository or my
GitHub account. Treat re-uploaded copies on other sites as untrusted.

There is no bug bounty.
